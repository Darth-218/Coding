import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Base64;
import java.util.List;

public class Client {
  public static void main(String[] args) {

    String username = null, password = null;

    for (int i = 0; i < args.length; i++) {
      switch (args[i]) {
      case "-u":
        if (i + 1 < args.length)
          username = args[++i];
        break;
      case "-p":
        if (i + 1 < args.length)
          password = args[++i];
        break;
      default:
        System.err.println("Unknown option: " + args[i]);
        System.exit(1);
      }
    }

    if (username == null || password == null) {
      System.err.println("Error: Username and password are required!");
      System.exit(1);
    }

    try {
      String json = Files.readString(Path.of("./envelop.json"));
      String authHeader =
          "Basic " +
          Base64.getEncoder().encodeToString(
              (username + ":" + password).getBytes(StandardCharsets.UTF_8));
      HttpClient client = HttpClient.newHttpClient();
      HttpRequest request =
          HttpRequest.newBuilder()
              .uri(URI.create("https://iajugs-test.fa.ocs.oraclecloud.com/"
                              + "fscmRestApi/resources/11.13.18.05"))
              .header("Authorization", authHeader)
              .header("Content-Type", "application/vnd.oracle.adf.batch+json")
              .POST(HttpRequest.BodyPublishers.ofString(json))
              .build();
      HttpResponse<String> response =
          client.send(request, HttpResponse.BodyHandlers.ofString());

      if (response.statusCode() == 200) {
        Files.write(Paths.get("response.json"), response.body().getBytes());
      } else {
        System.out.println(response.statusCode());
        System.out.println(response.body());
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}

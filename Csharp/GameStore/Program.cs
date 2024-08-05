using Gamestore.Dtos;

var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

List<GameDto> games = [
  new(1, "Game 1", "Action", 19.99M, new DateOnly(2000, 1, 1)),
  new(2, "Game 2", "Simulation", 49.99M, new DateOnly(2005, 8, 16)),
  new(3, "Game 3", "Adventure", 1.99M, new DateOnly(1992, 2, 1)),
];

app.MapGet("/", () => "Hello, games!");

app.MapGet("/games", () => games);

app.MapGet("/games/{id}", (int id) => games.Find(game => game.Id == id));

app.Run();

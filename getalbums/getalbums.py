import sys, os
from tinytag import TinyTag as tt

target_dir = sys.argv[1]
albums = []

files = os.walk(target_dir)
for (root, dir, file) in files:
    for song in file:
        song = os.path.join(root, song)
        if not tt.is_supported(song):
            print(f"{song} is not a song.")
            continue
        target_song = tt.get(song)
        album = target_song.album
        if album not in albums:
            albums.append(album)

with open("albums.md", "w") as albums_file:
    albums_file.write("\n- [ ] ".join(albums))

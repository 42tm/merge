# merge
Merge multiple files into one file

This program merge files continuously and skip any error about files.

## Usage
No need to say, this program is really easy to use. Below is how this program read parameters:
```
merge [output] [input_1] ...
```

Here,
- `[Output]` is Output file's name
- `[Input_n]` is nth input file's name

## Example

### Concatenate 2 files:
```
merge text3.txt text1.txt text2.txt
```

### Make a picture with music inside:
```
merge output.jpg image.jpg music.mp3
```


# Bineural Sine Wave Generator with Noise

This command-line tool allows users to generate stereo audio tracks with customizable sine waves and noise types. It supports generating files with two separate sine wave frequencies for the left and right channels. Users can also add white or pink noise to the track.

## Features
- **Generate Stereo Tracks**: Create stereo tracks with independent frequencies for each channel.
- **Custom Duration**: Set the track duration in minutes.
- **Add Noise**: Choose from no noise, white noise, or pink noise.
- **Command-Line Interface**: Simple argument structure for generating files directly from the command line.

---

## Usage

Run the following command in your terminal:
```
program_name generate <duration> <frequency_left> <frequency_right> <noiseType> <outputName>
```

### Arguments
| **Argument**  | **Description**                                   | **Example**          |
|---------------|--------------------------------------------------|---------------------|
| `function`    | Action to perform (`generate` or `help`)          | `generate`          |
| `duration`    | Duration of the track (in minutes)                 | `2` (for 2 minutes) |
| `frequency1`  | Frequency of the sine wave for the left channel (Hz) | `440` (for 440 Hz)  |
| `frequency2`  | Frequency of the sine wave for the right channel (Hz) | `450` (for 450 Hz)  |
| `noiseType`   | Noise type to add (0: None, 1: White, 2: Pink)     | `2` (for white noise) |
| `output`      | Name of the output file (with file extension)     | `output.wav`        |

### Example Commands

1. **Generate a 2-minute stereo track with 440 Hz on the left, 880 Hz on the right, and pink noise:**
   ```
   program_name generate 2 440 880 2 output.wav
   ```

2. **Generate a 3-minute track with 200 Hz on the left, 210 Hz on the right, and no noise (Which gives 10 Hz difference as bineural beat):**
   ```
   program_name generate 3 200 210 0 clean_tone.wav
   ```

3. **Display help instructions:**
   ```
   program_name help
   ```

---

## Installation
1. Clone the repository:
   ```
   git clone https://github.com/username/repository-name.git
   ```
2. Navigate to the project directory:
   ```
   cd repository-name
   ```
---

## Building with CMake

### Using Command Line (Linux/Mac/Windows)

1. Make sure you have **CMake** installed on your system.
2. Create a build directory:
   ```
   mkdir build && cd build
   ```
3. Run CMake to generate the build files:
   ```
   cmake ..
   ```
4. Compile the project:
   ```
   cmake --build .
   ```
5. Run the executable:
   ```
   ./program_name generate <duration> <frequency1> <frequency2> <noiseType> <output>
   ```

### Using Visual Studio (Windows)

1. Make sure **CMake** and **Visual Studio** are installed on your system.
2. Open the **CMake GUI**.
3. Set the source code folder to the location of the project.
4. Set the build directory to an empty directory (for example, `build/`).
5. Click **Configure** and choose **Visual Studio** as the generator.
6. Click **Generate** to create Visual Studio project files.
7. Open the generated **.sln** file in Visual Studio.
8. Build the solution in Visual Studio.
9. Run the executable using the **Debug** or **Release** configuration.


---

## How It Works
1. **Sine Wave Generation**: Two sine waves are generated using the specified frequencies.
2. **Noise Addition**: The user can choose to add white or pink noise to the track.
3. **Output**: The generated stereo track is saved as a WAV file.

---

## Possible Enhancements
- **Custom Sample Rate**: Allow users to set the sample rate.
- **More Noise Types**: Add support for other noise types (e.g., brown noise).
- **File Format Options**: Support file formats other than WAV (e.g., MP3, FLAC).
- **Custom Noise Mix Ratio**: Mix of noise ratio can be custumized.
- **Custom Noise Mix Ratio**: A simple gui can be added, as web server, electron or native.

---

## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any enhancements or bug fixes.

---

## License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

---

## Contact
For questions, feedback, or issues, please contact [Your Email] or open an issue in the repository.

---

Happy generating! 🎶

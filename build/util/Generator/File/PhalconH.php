<?php

declare(strict_types=1);

namespace Phalcon\Build;

/**
 * Generates phalcon.h
 */
class Generator_File_PhalconH
{
    /**
     * Directory with Phalcon source code
     *
     * @var string
     */
    protected string $sourceDir;

    /**
     * Path of generated phalcon.h file
     *
     * @var string
     */
    protected string $outputFile;

    /**
     * @param string $sourceDir
     * @param string $outputDir
     */
    public function __construct(string $sourceDir, string $outputDir)
    {
        $this->sourceDir = $sourceDir;
        $this->outputFile = $outputDir . DIRECTORY_SEPARATOR . 'phalcon.zep.h';
    }

    /**
     * Create phalcon.h by processing phalcon.h in sources directory:
     *  - Remove all extern declarations
     *  - Replace #include <file> with the direct file content
     * Return list of header files that are included in the generated phalcon.h
     *
     * @return array
     */
    public function generate(): array
    {
        $fileHandle = fopen($this->outputFile, 'w');

        $includedHeaderFiles = $this->appendFileAndReferencedHeaders($fileHandle, $this->sourceDir . '/phalcon.h');
        fclose($fileHandle);

        $this->limitVisibilityOfPhalconFunctions();

        return $includedHeaderFiles;
    }

    /**
     * Add source of $filePath, processing its content.
     * Also includes content of files, referenced from $filePath.
     *
     * @param resource $fileHandle
     * @param string $filePath
     * @return array
     */
    protected function appendFileAndReferencedHeaders($fileHandle, string $filePath): array
    {
        $includedHeaderFiles = array();

        foreach (file($filePath) as $line) {
            if (preg_match('/^#include "(.*)"/', $line, $matches)) {
                $relFile = $matches[1];
                $includedFile = $this->sourceDir . '/' . $relFile;
                $cleanSource = $this->getCleanHeaderFileContent($includedFile);
                fwrite($fileHandle, $cleanSource);
                $includedHeaderFiles[$relFile] = true;
            } else {
                $line = $this->cleanExtern($line);
                fwrite($fileHandle, $line);
            }
        }


        return $includedHeaderFiles;
    }

    /**
     * Return content of the header file, where comments like license notices are removed and no 'extern's present.
     * Overall, removing comments is not necessary for putting result to a merged file, we just don't
     * want to put license notices for every included file.
     *
     * @param string $file
     * @return string
     */
    protected function getCleanHeaderFileContent(string $file): string
    {
        $result = '';
        $openComment = false;
        foreach (file($file) as $line) {
            // Skip comments
            $trimLine = trim($line);
            if (($trimLine == '/*') || ($trimLine == '/**')) {
                $openComment = true;
                continue;
            }
            if ($openComment) {
                if (($trimLine == '*/') || ($trimLine == '**/')) {
                    $openComment = false;
                }
                continue;
            }

            // Add line to result
            $result .= $this->cleanExtern($line);
        }

        return $result;
    }

    /**
     * Remove 'extern ' declaration from the source file line
     *
     * @param string $line
     * @return string
     */
    protected function cleanExtern(string $line): string
    {
        if (strncmp($line, 'extern ', 7) === 0) {
            $line = substr($line, 7);
        }

        return $line;
    }

    /**
     * Go through the generated file and put 'static' to all declarations of Phalcon-related functions
     */
    protected function limitVisibilityOfPhalconFunctions(): void
    {
        $resContent = '';

        foreach (file($this->outputFile) as $line) {
            if (preg_match('/^PHP_METHOD\(([a-zA-Z0-9\_]+), ([a-zA-Z0-9\_]+)\)/', $line, $matches)) {
                $line = str_replace($matches[0], 'static PHP_METHOD(' . $matches[1] . ', ' . $matches[2] . ')', $line);
            }

            $line = preg_replace('/^PHALCON_STATIC /', 'static ', $line);
            $resContent .= $line;
        }

        file_put_contents($this->outputFile, $resContent);
    }
}

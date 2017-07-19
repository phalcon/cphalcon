<?php
namespace Phalcon\Build;

/**
 * Generates phalcon.c
 */
class Generator_File_PhalconC
{
    /**
     * Root directory of Phalcon
     *
     * @var string
     */
    protected $rootDir;

    /**
     * Directory with Phalcon source code
     *
     * @var string
     */
    protected $sourceDir;

    /**
     * Directory with configuration files, used to setup process of generating phalcon.c
     *
     * @var string
     */
    protected $configDir;

    /**
     * Path of generated phalcon.c file
     *
     * @var string
     */
    protected $outputFile;

    /**
     * List of files, which should not be included into generated phalcon.c
     *
     * @var array
     */
    protected $skipFiles;

    /**
     * @param string $rootDir
     * @param string $sourceDir
     * @param string $configDir
     * @param string $outputDir
     */
    public function __construct($rootDir, $sourceDir, $configDir, $outputDir)
    {
        $this->rootDir = $rootDir;
        $this->configDir = $configDir;
        $this->sourceDir = $sourceDir;

        $this->outputFile = $outputDir . '/phalcon.zep.c';
    }

    /**
     * Generate phalcon.h
     *
     * @param array $alreadyIncludedHeaders List of header files, which are already included in phalcon.h
     */
    public function generate(array $alreadyIncludedHeaders = array())
    {
        $this->composeSkipFiles($alreadyIncludedHeaders);

        $fileHandler = fopen($this->outputFile, 'w');

        $this->addLicense($fileHandler);
        $this->addStandardHeader($fileHandler);
        $this->addPriorityFiles($fileHandler);
        $this->addAllSourceFiles($fileHandler);

        fclose($fileHandler);

        $this->limitVisibilityOfPhalconFuncs();
    }

    /**
     * Composes list of files, which should not be scanned and put into phalcon.c during recursive scan of
     * the source directory
     *
     * @param array $alreadyIncludedHeaders
     */
    protected function composeSkipFiles(array $alreadyIncludedHeaders = array())
    {
        foreach (array_keys($alreadyIncludedHeaders) as $file) {
            $path = Util::normalize($this->sourceDir . '/' . $file);

            $this->skipFiles[$path] = true;
        }

        // Add custom list of skipped files
        $files = include($this->configDir . '/phalcon_c_skip_files.php');
        foreach ($files as $file) {
            $path = Util::normalize($this->sourceDir . '/' . $file);
            $this->skipFiles[$path] = true;
        }

        unset($this->skipFiles[0]);

        // Add phalcon.c, because it will be processed separately from other source files, i.e. appended at the very end
        $this->skipFiles[Util::normalize($this->sourceDir . '/phalcon.c')] = true;
    }

    /**
     * Add license notice to the generated file
     *
     * @param resource $fileHandler
     */
    protected function addLicense($fileHandler)
    {
        $docFile = $this->rootDir . '/LICENSE.txt';
        fwrite($fileHandler, '/**' . PHP_EOL . PHP_EOL . file_get_contents($docFile) . '*/' . PHP_EOL);
    }

    /**
     * Add manually-created header to the generated file
     *
     * @param resource $fileHandler
     */
    protected function addStandardHeader($fileHandler)
    {
        if (PHP_MAJOR_VERSION == 5) {
            $header = require $this->configDir . '/php5/phalcon_c_header.php';
        } else {
            $header = require $this->configDir . '/php7/phalcon_c_header.php';
        }
        fwrite($fileHandler, PHP_EOL . $header . PHP_EOL);
    }

    /**
     * Add contents of the files, which must be put to the generated file before other source files
     *
     * @param resource $fileHandler
     */
    protected function addPriorityFiles($fileHandler)
    {
        $files = include($this->configDir . '/phalcon_c_priority_files.php');
        foreach ($files as $file) {
            $this->appendSource($fileHandler, $this->sourceDir . '/' . $file);
            $this->skipFiles[$file] = true;
        }
    }

    /**
     * Recursively scan Phalcon sources and append content of all c-files to the generated file
     *
     * @param resource $fileHandler
     */
    protected function addAllSourceFiles($fileHandler)
    {
        /**
         * Sorting is important, so that the resulting contents doesn't fluctuate because of OS,
         * filesystem walk order, etc. Therefore the resulting file can be easily diff'ed
         * with its previous version in repository.
         */
        $cFiles = $this->getSortedSourceFilesToAppend($this->sourceDir);

        $hFiles = $this->extractReferencedHeaders($cFiles);

        foreach ($hFiles as $file) {
            $this->appendSource($fileHandler, $file);
        }

        foreach ($cFiles as $file) {
            $this->appendSource($fileHandler, $file);
        }

        $this->appendSource($fileHandler, $this->sourceDir . '/phalcon.c');
    }

    /**
     * Appends the source to phalcon.c, removing some directives, external symbol declarations and excessive comments
     */
    private function appendSource($fileHandler, $path)
    {
        if (!file_exists($path)) {
            return;
        }

        $openComment = false;
        foreach (file($path) as $line) {
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

            // Skip unneeded lines
            if ((strncmp($line, '#include "', 10) == 0) || (strncmp($line, '#include <', 10) == 0) || (strncmp($line, 'ZEPHIR_DOC_METHOD', 18) == 0) || (strncmp($line, '#line ', 6) == 0)) {
                continue;
            }

            // Clean externs, except for PHP API functions
            if (strncmp($line, 'extern ', 7) == 0) {
                if ((substr($line, 7, 8) == 'ZEND_API') || (substr($line, 7, 6) == 'PHPAPI')) {
                    fwrite($fileHandler, $line);
                } else {
                    fwrite($fileHandler, substr($line, 7));
                }
                continue;
            }

            // Ordinary line - put it as is
            fwrite($fileHandler, $line);
        }

        fwrite($fileHandler, PHP_EOL . PHP_EOL);
    }

    /**
     * Recursively walk through source files and return them in a sorted order.
     * Excludes unrelated files and the ones, which were already included by an other procedure.
     *
     * @param string $path
     * @return array|bool
     */
    protected function getSortedSourceFilesToAppend($path)
    {
        $basePathLen = strlen($this->sourceDir  . '/');
        $flags = \FilesystemIterator::CURRENT_AS_FILEINFO | \FilesystemIterator::SKIP_DOTS;
        $iterator = new \FilesystemIterator($path, $flags);

        $dirs = array();
        $files = array();
        foreach ($iterator as $item) {
            /** @var \SplFileInfo $item */
            $itemPath = Util::normalize($item->getPathname());
            if ($item->isDir()) {
                if (basename($itemPath) == 'kernel') { // These files must have been added already - before usual files
                    continue;
                }
                $dirs[] = $itemPath;
            } else {
                if (substr($itemPath, -2) != '.c') {
                    continue;
                }
                if (isset($this->skipFiles[$itemPath])) {
                    continue;
                }
                $files[] = $itemPath;
            }
        }

        // Compose result, by adding files and sub files to the list
        sort($files);
        $result = $files;
        foreach ($dirs as $dir) {
            $subFiles = $this->getSortedSourceFilesToAppend($dir);
            $result = array_merge($result, $subFiles);
        }

        return $result;
    }

    /**
     * Scan files' content and extract referenced header files
     *
     * @var array $files
     * @return array
     */
    protected function extractReferencedHeaders($files)
    {
        $result = array();
        $headers = array();
        $sourceDirLen = strlen($this->sourceDir);

        foreach ($files as $file) {
            foreach (file($file) as $line) {
                if (!preg_match('/^#include "(.+)"/', $line, $matches)) {
                    continue;
                }

                $headerFile = $matches[1];

                if (strpos($headerFile, 'kernel/') !== false) {
                    continue;
                }

                if (strpos($headerFile, 'Zend/') !== false) {
                    $headers[$headerFile] = true;
                    continue;
                }

                if (strpos($headerFile, 'main/') !== false) {
                    $headers[$headerFile] = true;
                    continue;
                }

                if (strpos($headerFile, 'ext/') !== false) {
                    $headers[$headerFile] = true;
                    continue;
                }

                if (strpos($headerFile, 'php_') !== false) {
                    $headers[$headerFile] = true;
                    continue;
                }

                if (strpos($headerFile, 'spl_') !== false) {
                    $headers[$headerFile] = true;
                    continue;
                }

                $possiblePathFromCurrent = Util::normalize('ext/' . $headerFile);
                if ($possiblePathFromCurrent == "") {
                    continue;
                }

                if (isset($this->skipFiles[$possiblePathFromCurrent])) {
                    continue;
                }

                $fullPath = $possiblePathFromCurrent;
                $result[$fullPath] = true;
            }
        }

        return array_keys($result);
    }

    /**
     * Go through the generated file and put 'static' to all declarations of Phalcon-related functions
     */
    protected function limitVisibilityOfPhalconFuncs()
    {
        $resContent = '';

        $prefixes = array('zephir', 'phalcon', 'phannot', 'phvolt', 'phql');
        foreach (file($this->outputFile) as $line) {

            $modified = true;
            foreach ($prefixes as $prefix) {
                if (preg_match('/^int ' . $prefix . '_/i', $line)) {
                    $line = 'static ' . $line;
                    break;
                }

                if (preg_match('/^void ' . $prefix . '_/i', $line)) {
                    $line = 'static ' . $line;
                    break;
                }

                if (preg_match('/^zend_class_entry *' . $prefix . '_/i', $line)) {
                    $line = 'static ' . $line;
                    break;
                }

                $modified = false;
            }

            if (!$modified) {
                if (preg_match('/^PHP_METHOD\(([a-zA-Z0-9\_]+), ([a-zA-Z0-9\_]+)\)/', $line, $matches)) {
                    $line = str_replace($matches[0], 'static PHP_METHOD(' . $matches[1] . ', ' . $matches[2] . ')', $line);
                }
            }

            $resContent .= $line;
        }

        file_put_contents($this->outputFile, $resContent);
    }
}

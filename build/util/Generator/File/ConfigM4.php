<?php
namespace Phalcon\Build;

/**
 * Generates config.m4
 */
class Generator_File_ConfigM4
{
    /**
     * Path of original config.m4, which will be used to generate build config.m4
     *
     * @var string
     */
    protected string $sourceFile;

    /**
     * Path of generated config.m4 file
     *
     * @var string
     */
    protected string $outputFile;

    /**
     * @param string $rootDir
     * @param string $outputDir
     */
    public function __construct(string $rootDir, string $outputDir)
    {
        $this->sourceFile = $rootDir . str_replace('/', DIRECTORY_SEPARATOR, '/build/config/config.m4');
        $this->outputFile = $outputDir . DIRECTORY_SEPARATOR . '/config.m4';
    }

    /**
     * Create config.m4 from the original one, by leaving only "phalcon.c" among included source files
     *
     * @return bool
     */
    public function generate(): bool
    {
        return copy($this->sourceFile, $this->outputFile);
    }
}

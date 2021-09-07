<?php

declare(strict_types=1);

namespace Phalcon\Build;

/**
 * Generates config.w32
 */
class Generator_File_ConfigW32
{
    /**
     * Path of original config.w32, which will be used to generate build config.m4
     *
     * @var string
     */
    protected string $sourceFile;

    /**
     * Path of generated config.w32 file
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
        $this->sourceFile = $rootDir . str_replace('/', DIRECTORY_SEPARATOR, '/build/config/config.w32');
        $this->outputFile = $outputDir . DIRECTORY_SEPARATOR . 'config.w32';
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

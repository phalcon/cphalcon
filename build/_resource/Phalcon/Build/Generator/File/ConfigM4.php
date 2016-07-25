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
    protected $sourceFile;

    /**
     * Path of generated config.m4 file
     *
     * @var string
     */
    protected $outputFile;

    /**
     * @param string $sourceDir
     * @param string $outputDir
     */
    public function __construct($sourceDir, $outputDir)
    {
        $this->sourceFile = 'build/_resource/config/config.m4';
        $this->outputFile = $outputDir . '/config.m4';
    }

    /**
     * Create config.m4 from the original one, by leaving only "phalcon.c" among included source files
     *
     * @return array
     */
    public function generate()
    {
        copy($this->sourceFile, $this->outputFile);
    }
}

<?php
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
    protected $sourceFile;

    /**
     * Path of generated config.w32 file
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
        $this->sourceFile = 'build/_resource/config/config.w32';
        $this->outputFile = $outputDir . '/config.w32';
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

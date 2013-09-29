<?php
namespace Phalcon\Build;

/**
 * Generates config.m4
 */
class Generator_File_MakefileFrag
{
    /**
     * Path of original Makefile.frag, which will be used to generate build Makefile.frag
     *
     * @var string
     */
    protected $sourceFile;

    /**
     * Path of generated Makefile.frag file
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
        $this->sourceFile = $sourceDir . '/Makefile.frag';
        $this->outputFile = $outputDir . '/Makefile.frag';
    }

    /**
     * Create Makefile.frag from the original one
     */
    public function generate()
    {
        $content = file_get_contents($this->sourceFile);
        $content = str_replace('$(top_srcdir)/../', '$(top_srcdir)/../../', $content);
        file_put_contents($this->outputFile, $content);
    }
}

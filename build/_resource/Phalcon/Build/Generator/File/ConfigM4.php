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
        $this->sourceFile = $sourceDir . '/config.m4';
        $this->outputFile = $outputDir . '/config.m4';
    }

    /**
     * Create config.m4 from the original one, by leaving only "phalcon.c" among included source files
     *
     * @return array
     */
    public function generate()
    {
        $originalContent = file_get_contents($this->sourceFile);

        // Remove all the c-files, mentioned in config - we have only phalcon.c to compile
        $generatedContent = preg_replace(
            '/phalcon_sources=.*PHP_NEW_EXTENSION\(phalcon,.*?\n/s',
            "PHP_NEW_EXTENSION(phalcon, phalcon.c, \$ext_shared)\n",
            $originalContent
        );

        file_put_contents($this->outputFile, $generatedContent);
    }
}

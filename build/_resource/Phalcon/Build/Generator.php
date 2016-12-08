<?php

namespace Phalcon\Build;

class Generator
{
    /**
     * Root dir of Phalcon
     *
     * @var string
     */
    protected $rootDir;

    /**
     * Directory for 'safe' build
     *
     * @var string
     */
    protected $safeDir;

    /**
     * Directory for build, optimized for 32-bit platform
     *
     * @var string
     */
    protected $optimized32Dir;

    /**
     * Directory for build, optimized for 64-bit platform
     *
     * @var string
     */
    protected $optimized64Dir;

    /**
     * @param string $rootDir
     * @param string $buildDir
     */
    public function __construct($rootDir, $buildDir)
    {
        $this->rootDir = $rootDir;
        $this->safeDir = $buildDir . '/safe';

        $this->optimized32Dir = $buildDir . '/32bits';
        $this->optimized64Dir = $buildDir . '/64bits';
    }

    /**
     * Generate safe and optimized builds
     */
    public function run()
    {
        $generator = new Generator_Safe($this->rootDir, $this->safeDir);
        $generator->run();

        $generatorOptimized = new Generator_Optimized($this->safeDir, $this->optimized32Dir, $this->optimized64Dir);
        $generatorOptimized->run();
    }
}

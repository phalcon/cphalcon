<?php

namespace Phalcon\Build;

use Phalcon\Kernel;

/**
 * Uses previously generated safe universal build and generates optimized build for a specific platform
 */
class Generator_Optimized
{
    /**
     * Directory, where safe universal build files are generated
     *
     * @var string
     */
    protected $sourceBuildDir;

    /**
     * Platform settings for supported optimized builds
     *
     * @var array
     */
    protected $settings;

    /**
     * Filters for processing (optimizing) lines from safe universal phalcon.c
     *
     * @var array
     */
    protected $filters;

    /**
     * @param string $sourceBuildDir
     * @param string $output32Dir
     * @param string $output64Dir
     */
    public function __construct($sourceBuildDir, $output32Dir, $output64Dir)
    {
        $this->sourceBuildDir = $sourceBuildDir;
        $this->settings = $this->getPlatformsSettings($output32Dir, $output64Dir);
        $this->filters = $this->getFilters();
    }

    /**
     * Return array of supported platform settings for optimized builds
     *
     * @param string $output32Dir
     * @param string $output64Dir
     * @return array
     */
    protected function getPlatformsSettings($output32Dir, $output64Dir)
    {
        return array(
            '32bit' => array(
                'dir' => $output32Dir,
                'hashFunc' => function ($string) {
                    return Kernel::preComputeHashKey32($string) . 'UL';
                }
            ),
            '64bit' => array(
                'dir' => $output64Dir,
                'hashFunc' => function ($string) {
                    return Kernel::preComputeHashKey64($string) . 'UL';
                }
            ),
        );
    }

    /**
     * Return filters for processing lines from safe universal phalcon.c
     *
     * @return array
     */
    protected function getFilters()
    {
        $result = array();

        /*
        // Explicit calls to zend_inline_hash_func()
        $result[] = array(
            'regexp' => '/(zend_inline_hash_func\(SS\("([^"]++)"\)\))/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[2]);
                return str_replace($matches[1], $hash, $line);
            }
        );

        // Pre-compute the hash key for isset using strings
        $result[] = array(
            'regexp' => '/zephir_array_isset_string\(([a-zA-Z0-9\_]+), SS\("([a-zA-Z\_\-]+)"\)\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[2]);
                return str_replace($matches[0], 'zephir_array_isset_quick_string('.$matches[1].', SS("'.$matches[2].'"), '.$hash.')', $line);
            }
        );

        // Pre-compute the hash key for reading elements using hashes
        $result[] = array(
            'regexp' => '/zephir_array_fetch_string\(\&([a-zA-Z0-9\_]+), ([a-zA-Z0-9\_]+), SL\("([a-zA-Z\_\-]+)"\), ([a-zA-Z0-9\_]+)\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[3]);
                return str_replace($matches[0], 'zephir_array_fetch_quick_string(&'.$matches[1].', '.$matches[2].', SS("'.$matches[3].'"), '.$hash.', '.$matches[4].')', $line);
            }
        );

        // Pre-compute hash for updating elements
        $result[] = array(
            'regexp' => '/zephir_array_update_string\(\&([a-zA-Z0-9\_]+), SL\("([a-zA-Z\_\-]+)"\), \&([a-zA-Z0-9\_]+), (.+)\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[2]);
                return str_replace($matches[0], 'zephir_array_update_quick_string(&'.$matches[1].', SS("'.$matches[2].'"), '.$hash.', &'.$matches[3].', '.$matches[4].')', $line);
            }
        );

        // Pre-compute hash key for method checking
        $result[] = array(
            'regexp' => '/zephir_method_exists_ex\(([a-zA-Z0-9\_]+), SS\("([a-zA-Z\_\-]+)"\) TSRMLS_CC\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[2]);
                return str_replace($matches[0], 'zephir_method_quick_exists_ex('.$matches[1].', SS("'.$matches[2].'"), '.$hash.' TSRMLS_CC)', $line);
            }
        );

        // Pre-compute hash key for function checking
        $result[] = array(
            'regexp' => '/zephir_function_exists_ex\(SS\("([a-zA-Z\_\-]+)"\) TSRMLS_CC\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[1]);
                return str_replace($matches[0], 'zephir_function_quick_exists_ex(SS("'.$matches[1].'"), '.$hash.' TSRMLS_CC)', $line);
            }
        );

        $result[] = array(
            'regexp' => '/zephir_read_property_this\(&([a-zA-Z0-9\_]+), this_ptr, SL\("([a-zA-Z0-9\_]+)"\), PH_NOISY_CC\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[2]);
                return str_replace($matches[0], 'zephir_read_property_this_quick(&'.$matches[1].', this_ptr, SL("'.$matches[2].'"), '.$hash.', PH_NOISY_CC)', $line);
            }
        );

        $result[] = array(
            'regexp' => '/zephir_update_property_this\(this_ptr, SL\("([a-zA-Z0-9\_]+)"\), ([a-zA-Z0-9\_]+) TSRMLS_CC\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $key = $hashFunc($matches[1]);
                return str_replace($matches[0], 'zephir_update_property_this_quick(this_ptr, SL("'.$matches[1].'"), '.$matches[2].', '.$key.' TSRMLS_CC)', $line);
            }
        );

        $result[] = array(
            'regexp' => '/RETURN_MEMBER\(([a-zA-Z0-9\_]+), "([a-zA-Z0-9\_]+)"\)/',
            'func' => function ($line, $matches, $hashFunc) {
                $hash = $hashFunc($matches[2]);
                return str_replace($matches[0], 'RETURN_MEMBER_QUICK('.$matches[1].', "'.$matches[2].'", '.$hash.')', $line);
            }
        );*/

        return $result;
    }

    /**
     * Run generation process
     */
    public function run()
    {
        echo 'Generating builds, optimized for 32-bit and 64-bit platforms... ';

        if (!extension_loaded('phalcon')) {
            echo "SKIPPED - Phalcon extension is required to be already loaded in PHP\n";
            // You need to compile safe Phalcon extension, enable it in PHP, and then you can compile optimized version
            return;
        }

        $this->cleanBuildDirectories();
        $this->copyFilesFromSourceBuildDir();
        $this->copyAndOptimizePhalconC();

        echo "OK\n";
    }

    /**
     * Delete all files in target directories
     */
    public function cleanBuildDirectories()
    {
        foreach ($this->settings as $setting) {
            Util::cleanDirectory($setting['dir']);
        }
    }

    /**
     * Copy all files from the original safe universal build directory
     */
    protected function copyFilesFromSourceBuildDir()
    {
        $files = glob($this->sourceBuildDir . '/*.*');
        foreach ($files as $file) {
            // phalcon.c is processed in a separate optimization func
            if (basename($file) == 'phalcon.zep.c') {
                continue;
            }

            foreach ($this->settings as $setting) {
                copy($file, $setting['dir'] . '/' . basename($file));
            }
        }
    }

    /**
     * Copy phalcon.c and optimize it by replacing specific strings with the precalculated hash values.
     * Precalculation is, actually, the optimization being performed.
     */
    protected function copyAndOptimizePhalconC()
    {
        $platforms = array_keys($this->settings);

        // Init generated content
        $generated = array();
        foreach ($platforms as $platform) {
            $generated[$platform] = '';
        }

        // Generate line by line
        $filePath = $this->sourceBuildDir . '/phalcon.zep.c';
        foreach (file($filePath) as $line) {
            $this->filterLine($line, $generated);
        }

        // Output result
        foreach ($platforms as $platform) {
            file_put_contents($this->settings[$platform]['dir'] . '/phalcon.zep.c', $generated[$platform]);
        }
    }

    /**
     * Pass line through filters and add the processed result to platform builds
     *
     * @param string $line
     * @param array $result
     */
    protected function filterLine($line, &$result)
    {
        /** @var callable|null $func */
        $func = null;
        foreach ($this->filters as $filter) {
            if (!preg_match($filter['regexp'], $line, $matches)) {
                continue;
            }
            $func = $filter['func'];
            break; // We don't expect more than one replacement to be made on the same line
        }

        foreach ($this->settings as $platform => $setting) {
            $result[$platform] .= $func ? $func($line, $matches, $setting['hashFunc']) : $line;
        }
    }
}

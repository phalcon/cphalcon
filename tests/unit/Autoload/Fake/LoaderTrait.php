<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Autoload\Fake;

trait LoaderTrait
{
    /**
     * @var string
     */
    protected string $includePath = '';

    /**
     * @var array
     */
    protected array $loaders = [];

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->loaders = spl_autoload_functions();

        if (!is_array($this->loaders)) {
            $this->loaders = [];
        }

        $this->includePath = get_include_path();
    }

    /**
     * Executed after each test
     *
     * @return void
     */
    public function tearDown(): void
    {
        $loaders = spl_autoload_functions();

        if (is_array($loaders)) {
            foreach ($loaders as $loader) {
                spl_autoload_unregister($loader);
            }
        }

        foreach ($this->loaders as $loader) {
            spl_autoload_register($loader);
        }

        set_include_path($this->includePath);
    }
}

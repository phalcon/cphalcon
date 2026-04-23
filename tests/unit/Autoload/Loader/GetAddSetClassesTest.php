<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Autoload\Loader;

use Phalcon\Autoload\Loader;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Autoload\Fake\LoaderTrait;

final class GetAddSetClassesTest extends AbstractUnitTestCase
{
    use LoaderTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAutoloaderLoaderGetAddSetClasses(): void
    {
        $loader = new Loader();

        $expected = [];
        $actual   = $loader->getClasses();
        $this->assertSame($expected, $actual);

        $source = [
            'one' => 'classOne.php',
            'two' => 'classTwo.php',
        ];
        $loader->setClasses($source);

        $expected = $source;
        $actual   = $loader->getClasses();
        $this->assertSame($expected, $actual);

        /**
         * Clear
         */
        $loader->setClasses([]);

        $expected = [];
        $actual   = $loader->getClasses();
        $this->assertSame($expected, $actual);

        $loader
            ->addClass('one', 'classOne.php')
            ->addClass('two', 'classTwo.php')
            ->addClass('one', 'classOne.php')
        ;
        $expected = $source;
        $actual   = $loader->getClasses();
        $this->assertSame($expected, $actual);
    }
}

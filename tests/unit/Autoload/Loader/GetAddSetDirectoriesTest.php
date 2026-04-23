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

use function hash;

final class GetAddSetDirectoriesTest extends AbstractUnitTestCase
{
    use LoaderTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAutoloaderLoaderGetAddSetDirectories(): void
    {
        $loader = new Loader();

        $expected = [];
        $actual   = $loader->getDirectories();
        $this->assertSame($expected, $actual);

        $loader->setDirectories(
            [
                '/phalcon/public/css',
                '/phalcon/public/css',
                '/phalcon/public/css',
            ]
        );
        $expected = [hash("sha256", '/phalcon/public/css') => '/phalcon/public/css'];
        $actual   = $loader->getDirectories();
        $this->assertSame($expected, $actual);

        /**
         * Clear
         */
        $loader->setDirectories([]);

        $expected = [];
        $actual   = $loader->getDirectories();
        $this->assertSame($expected, $actual);

        $loader
            ->addDirectory('/phalcon/public/css')
            ->addDirectory('/phalcon/public/js')
            ->addDirectory('/phalcon/public/css')
        ;

        $expected = [
            hash("sha256", '/phalcon/public/css') => '/phalcon/public/css',
            hash("sha256", '/phalcon/public/js')  => '/phalcon/public/js',
        ];
        $actual   = $loader->getDirectories();
        $this->assertSame($expected, $actual);
    }
}

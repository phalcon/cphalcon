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
use Phalcon\Tests\Fixtures\Traits\LoaderTrait;
use UnitTester;

class GetAddSetDirectoriesCest
{
    use LoaderTrait;

    /**
     * Tests Phalcon\Autoload\Loader :: getDirectories()/addDirectory()/setDirectories()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderGetAddSetDirectories(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - getDirectories()/addDirectory()/setDirectories()');

        $loader = new Loader();

        $expected = [];
        $actual   = $loader->getDirectories();
        $I->assertEquals($expected, $actual);

        $loader->setDirectories(
            [
                '/phalcon/public/css',
                '/phalcon/public/css',
                '/phalcon/public/css',
            ]
        );
        $expected = [hash("sha256", '/phalcon/public/css') => '/phalcon/public/css'];
        $actual   = $loader->getDirectories();
        $I->assertEquals($expected, $actual);

        /**
         * Clear
         */
        $loader->setDirectories([]);

        $expected = [];
        $actual   = $loader->getDirectories();
        $I->assertEquals($expected, $actual);

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
        $I->assertEquals($expected, $actual);
    }
}

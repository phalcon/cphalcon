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

class GetAddSetFilesCest
{
    use LoaderTrait;

    /**
     * Tests Phalcon\Autoload\Loader :: getFiles()/addFile()/setFile()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderGetAddSetFiles(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - getFiles()/addFile()/setFile()');

        $loader = new Loader();

        $expected = [];
        $actual   = $loader->getFiles();
        $I->assertEquals($expected, $actual);

        $loader->setFiles(
            [
                'classOne.php',
                'classOne.php',
                'classOne.php',
            ]
        );
        $expected = [sha1('classOne.php') => 'classOne.php'];
        $actual   = $loader->getFiles();
        $I->assertEquals($expected, $actual);

        /**
         * Clear
         */
        $loader->setFiles([]);

        $expected = [];
        $actual   = $loader->getFiles();
        $I->assertEquals($expected, $actual);

        $loader
            ->addFile('classOne.php')
            ->addFile('classTwo.php')
            ->addFile('classOne.php')
        ;

        $expected = [
            sha1('classOne.php') => 'classOne.php',
            sha1('classTwo.php') => 'classTwo.php',
        ];
        $actual   = $loader->getFiles();
        $I->assertEquals($expected, $actual);
    }
}

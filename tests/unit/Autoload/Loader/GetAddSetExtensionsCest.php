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

use function hash;

class GetAddSetExtensionsCest
{
    use LoaderTrait;

    /**
     * Tests Phalcon\Autoload\Loader ::
     * getExtensions()/addExtension()/setExtension()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function autoloaderLoaderGetAddSetExtensions(UnitTester $I)
    {
        $I->wantToTest('Autoload\Loader - getExtensions()/addExtension()/setExtension()');

        $loader = new Loader();

        $expected = [hash("sha256", 'php') => 'php'];
        $actual   = $loader->getExtensions();
        $I->assertEquals($expected, $actual);

        $loader->setExtensions(
            [
                'inc',
                'inc',
                'inc',
            ]
        );

        $expected = [
            hash("sha256", 'php') => 'php',
            hash("sha256", 'inc') => 'inc',
        ];
        $actual   = $loader->getExtensions();
        $I->assertEquals($expected, $actual);

        /**
         * Clear
         */
        $loader->setExtensions([]);
        $expected = [hash("sha256", 'php') => 'php'];
        $actual   = $loader->getExtensions();
        $I->assertEquals($expected, $actual);


        $loader
            ->addExtension('inc')
            ->addExtension('phpt')
            ->addExtension('inc')
        ;
        $expected = [
            hash("sha256", 'php')  => 'php',
            hash("sha256", 'inc')  => 'inc',
            hash("sha256", 'phpt') => 'phpt',
        ];
        $actual   = $loader->getExtensions();
        $I->assertEquals($expected, $actual);
    }
}

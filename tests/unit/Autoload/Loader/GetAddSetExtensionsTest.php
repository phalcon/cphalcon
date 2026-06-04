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

final class GetAddSetExtensionsTest extends AbstractUnitTestCase
{
    use LoaderTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAutoloaderLoaderGetAddSetExtensions(): void
    {
        $loader = new Loader();

        $expected = ['php' => 'php'];
        $actual   = $loader->getExtensions();
        $this->assertSame($expected, $actual);

        $loader->setExtensions(
            [
                'inc',
                'inc',
                'inc',
            ]
        );

        $expected = [
            'php' => 'php',
            'inc' => 'inc',
        ];
        $actual   = $loader->getExtensions();
        $this->assertSame($expected, $actual);

        /**
         * Clear
         */
        $loader->setExtensions([]);
        $expected = ['php' => 'php'];
        $actual   = $loader->getExtensions();
        $this->assertSame($expected, $actual);

        $loader
            ->addExtension('inc')
            ->addExtension('phpt')
            ->addExtension('inc')
        ;
        $expected = [
            'php'  => 'php',
            'inc'  => 'inc',
            'phpt' => 'phpt',
        ];
        $actual   = $loader->getExtensions();
        $this->assertSame($expected, $actual);
    }
}

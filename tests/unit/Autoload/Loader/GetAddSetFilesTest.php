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

final class GetAddSetFilesTest extends AbstractUnitTestCase
{
    use LoaderTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAutoloaderLoaderGetAddSetFiles(): void
    {
        $loader = new Loader();

        $expected = [];
        $actual   = $loader->getFiles();
        $this->assertSame($expected, $actual);

        $loader->setFiles(
            [
                'classOne.php',
                'classOne.php',
                'classOne.php',
            ]
        );
        $expected = [hash("sha256", 'classOne.php') => 'classOne.php'];
        $actual   = $loader->getFiles();
        $this->assertSame($expected, $actual);

        /**
         * Clear
         */
        $loader->setFiles([]);

        $expected = [];
        $actual   = $loader->getFiles();
        $this->assertSame($expected, $actual);

        $loader
            ->addFile('classOne.php')
            ->addFile('classTwo.php')
            ->addFile('classOne.php')
        ;

        $expected = [
            hash("sha256", 'classOne.php') => 'classOne.php',
            hash("sha256", 'classTwo.php') => 'classTwo.php',
        ];
        $actual   = $loader->getFiles();
        $this->assertSame($expected, $actual);
    }
}

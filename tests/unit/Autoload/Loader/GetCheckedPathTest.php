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

use Phalcon\Autoload\Exception;
use Phalcon\Autoload\Loader;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Autoload\Fake\LoaderTrait;

final class GetCheckedPathTest extends AbstractUnitTestCase
{
    use LoaderTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testAutoloaderLoaderGetCheckedPath(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $loader    = new Loader(true);
        $directory = supportDir('assets/Loader/Example/Folders/Types/');
        $loader->addDirectory($directory);

        $loader->autoload('Integer');

        $expected = [
            'Loading: Integer',
            'Class: 404: Integer',
            'Namespace: 404: Integer',
            'Require: ' . $directory . 'Integer.php',
            'Directories: ' . $directory . 'Integer.php',
        ];
        $actual   = $loader->getDebug();
        $this->assertSame($expected, $actual);

        $expected = $directory . 'Integer.php';
        $actual   = $loader->getCheckedPath();
        $this->assertSame($expected, $actual);
    }
}

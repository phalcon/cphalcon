<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

final class ReadTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAnnotationsAdapterStreamRead(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $adapter = new Stream(
            [
                'annotationsDir' => Talon::settings()->outputPath('tests/annotations/'),
            ]
        );

        $classAnnotations = $adapter->get(TestClass::class);

        $adapter->write('testwrite', $classAnnotations);

        $this->assertFileExists(Talon::settings()->outputPath('tests/annotations/testclass.php'));

        $newClass = $adapter->read('testwrite');
        $this->assertInstanceOf(Reflection::class, $newClass);

        $this->safeDeleteFile(Talon::settings()->outputPath('tests/annotations/testwrite.php'));
        $this->safeDeleteFile(Talon::settings()->outputPath('tests/annotations/testclass.php'));
    }

    /**
     * A cache file with no header, from an earlier version, is read as it is
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17812
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     */
    public function testAnnotationsAdapterStreamReadNoHeader(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $dir     = Talon::settings()->outputPath('tests/annotations/');
        $adapter = new Stream(['annotationsDir' => $dir]);

        $classAnnotations = $adapter->get(TestClass::class);

        $path = $dir . 'noheader.php';
        file_put_contents($path, serialize($classAnnotations));

        $actual = $adapter->read('noheader');

        $this->safeDeleteFile($path);
        $this->safeDeleteFile($dir . 'testclass.php');

        $this->assertInstanceOf(Reflection::class, $actual);
        $this->assertEquals($classAnnotations, $actual);
    }
}

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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;

final class WriteTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAnnotationsAdapterStreamWrite(): void
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

        $this->safeDeleteFile(Talon::settings()->outputPath('tests/annotations/testwrite.php'));
        $this->safeDeleteFile(Talon::settings()->outputPath('tests/annotations/testclass.php'));
    }

    /**
     * "Test\\Write" and "Test_Write" both normalize to "test_write"; the
     * second gets a hash suffix so the two never share a cache file.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testAnnotationsAdapterStreamWriteNoCollision(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $dir     = Talon::settings()->outputPath('tests/annotations/');
        $adapter = new Stream(['annotationsDir' => $dir]);

        $classAnnotations = $adapter->get(TestClass::class);

        $adapter->write('Test\\Write', $classAnnotations);
        $adapter->write('Test_Write', $classAnnotations);

        $files = glob($dir . 'test_write*.php');

        $this->safeDeleteFile($dir . 'testclass.php');
        foreach ($files as $file) {
            $this->safeDeleteFile($file);
        }

        $this->assertCount(2, $files);
        $this->assertContains($dir . 'test_write.php', $files);
    }
}

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
     * The name of an anonymous class has a NUL byte, and the file name stops
     * there. Two anonymous classes must not share a cache file.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17810
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     */
    public function testAnnotationsAdapterStreamWriteAnonymousClassNoCollision(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $dir     = Talon::settings()->outputPath('tests/annotations/');
        $adapter = new Stream(['annotationsDir' => $dir]);

        $classAnnotations = $adapter->get(TestClass::class);

        $adapter->write("class@anonymous\0/app/Invoices.php:10\$0", $classAnnotations);
        $adapter->write("class@anonymous\0/app/Invoices.php:20\$1", $classAnnotations);

        $files = glob($dir . 'class@anonymous*.php');

        $this->safeDeleteFile($dir . 'testclass.php');
        foreach ($files as $file) {
            $this->safeDeleteFile($file);
        }

        $this->assertCount(2, $files);
        $this->assertNotContains($dir . 'class@anonymous.php', $files);
    }

    /**
     * A cache file starts with a header that stops PHP, so a web request to
     * the file shows nothing.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17812
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     */
    public function testAnnotationsAdapterStreamWriteFileHeader(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');

        $dir     = Talon::settings()->outputPath('tests/annotations/');
        $adapter = new Stream(['annotationsDir' => $dir]);

        $adapter->get(TestClass::class);

        $path     = $dir . 'testclass.php';
        $contents = (string) file_get_contents($path);

        ob_start();
        try {
            include $path;
        } finally {
            $output = ob_get_clean();
            $this->safeDeleteFile($path);
        }

        $this->assertSame('<?php __halt_compiler();', Stream::FILE_HEADER);
        $this->assertStringStartsWith(Stream::FILE_HEADER, $contents);
        $this->assertSame('', $output);
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

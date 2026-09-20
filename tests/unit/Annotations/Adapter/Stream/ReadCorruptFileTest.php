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
use Phalcon\Annotations\Exceptions\CannotReadAnnotationData;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

use function file_put_contents;
use function is_dir;
use function mkdir;

use const PHP_VERSION_ID;

final class ReadCorruptFileTest extends AbstractUnitTestCase
{
    /**
     * A cache file that does not hold serialized data raises an error, and
     * the adapter reports it.
     *
     * The adapter traps E_WARNING, as the C implementation does. PHP raised
     * this diagnostic of unserialize() as E_NOTICE before 8.3, so the test
     * runs on 8.3 and later only.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterStreamReadCorruptFile(): void
    {
        if (PHP_VERSION_ID < 80300) {
            $this->markTestSkipped(
                'unserialize() raises E_NOTICE for corrupt data before PHP 8.3'
            );
        }

        $dir = Talon::settings()->outputPath('tests/annotations/');
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }

        $path = $dir . 'corruptfile.php';
        file_put_contents($path, 'this is not serialized data');

        $adapter = new Stream(['annotationsDir' => $dir]);

        try {
            $adapter->read('corruptfile');
            $this->fail('CannotReadAnnotationData was not thrown');
        } catch (CannotReadAnnotationData $ex) {
            $this->assertSame('Cannot read annotation data', $ex->getMessage());
        } finally {
            $this->safeDeleteFile($path);
        }
    }
}

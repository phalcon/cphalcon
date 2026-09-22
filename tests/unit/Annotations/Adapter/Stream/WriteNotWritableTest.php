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
use Phalcon\Annotations\Exceptions\AnnotationsDirectoryNotWritable;
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

use function restore_error_handler;
use function set_error_handler;

final class WriteNotWritableTest extends AbstractUnitTestCase
{
    /**
     * A directory that does not exist cannot take the cache file.
     *
     * The failed write raises E_WARNING, which the suite treats as a
     * failure, so the handler swallows it while the call runs.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterStreamWriteNotWritable(): void
    {
        $adapter = new Stream(
            [
                'annotationsDir' => Talon::settings()->outputPath('tests/annotations-missing/'),
            ]
        );

        set_error_handler(
            static function (): bool {
                return true;
            }
        );

        try {
            $adapter->write('notwritable', new Reflection());
            $this->fail('AnnotationsDirectoryNotWritable was not thrown');
        } catch (AnnotationsDirectoryNotWritable $ex) {
            $this->assertSame(
                'Annotations directory cannot be written',
                $ex->getMessage()
            );
        } finally {
            restore_error_handler();
        }
    }
}

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

use function file_put_contents;
use function is_dir;
use function mkdir;

final class ReadEmptyFileTest extends AbstractUnitTestCase
{
    /**
     * A cache file with no content is a miss, the same as a missing file.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterStreamReadEmptyFile(): void
    {
        $dir = Talon::settings()->outputPath('tests/annotations/');
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }

        $path = $dir . 'emptyfile.php';
        file_put_contents($path, '');

        $adapter = new Stream(['annotationsDir' => $dir]);

        $this->assertFalse($adapter->read('emptyfile'));

        $this->safeDeleteFile($path);
    }
}

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

namespace Phalcon\Tests\Unit\Session\Adapter\Stream;

use Phalcon\Session\Adapter\Stream;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class TraversalTest extends AbstractUnitTestCase
{
    /**
     * A session id carrying path separators must not let a direct handler call
     * write outside the session directory (CWE-22).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testSessionAdapterStreamWriteCannotEscapeSavePath(): void
    {
        $dir = Talon::settings()->outputPath('tests/session-d8/');
        if (!is_dir($dir)) {
            mkdir($dir, 0777, true);
        }

        $escape = Talon::settings()->outputPath('tests/pwned-d8-escape');
        @unlink($escape);

        $adapter = new Stream(['savePath' => $dir]);
        $adapter->write('../pwned-d8-escape', 'payload');

        // The id must have been sanitized: nothing written one level up.
        $this->assertFileDoesNotExist($escape);
        // It lands inside the session directory instead.
        $this->assertFileExists($dir . '.._pwned-d8-escape');

        @unlink($dir . '.._pwned-d8-escape');
        @unlink($escape);
    }
}

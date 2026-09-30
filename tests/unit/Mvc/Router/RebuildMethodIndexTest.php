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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Support\Mvc\RouterIndexFixture;

use function file_get_contents;
use function json_decode;

use const JSON_THROW_ON_ERROR;

final class RebuildMethodIndexTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-29
     */
    public function testMvcRouterRebuildMethodIndexDump(): void
    {
        $file     = Talon::settings()->supportPath('assets/Mvc/router-index-dump.json');
        $expected = json_decode(
            (string) file_get_contents($file),
            true,
            512,
            JSON_THROW_ON_ERROR
        );

        $this->assertSame($expected, RouterIndexFixture::dump());
    }
}

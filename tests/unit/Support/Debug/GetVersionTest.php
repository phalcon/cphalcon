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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Support\Version;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetVersionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugGetVersion(): void
    {
        $debug = new Debug();
        $version = new Version();

        $link = "https://docs.phalcon.io/"
               . $version->getPart(Version::VERSION_MAJOR) . '.'
               . $version->getPart(Version::VERSION_MEDIUM) . "/";
        $versionString = $version->get();

        $expected = "<a class='version-badge' href='{$link}' target='_new'><b>v{$versionString}</b></a>";

        $actual = $debug->getVersion();
        $this->assertSame($expected, $actual);
    }
}

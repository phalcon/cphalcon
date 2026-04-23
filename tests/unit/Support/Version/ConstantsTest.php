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

namespace Phalcon\Tests\Unit\Support\Version;

use Phalcon\Support\Version;
use Phalcon\Tests\AbstractUnitTestCase;

final class ConstantsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportVersionConstants(): void
    {
        $this->assertSame(0, Version::VERSION_MAJOR);
        $this->assertSame(1, Version::VERSION_MEDIUM);
        $this->assertSame(2, Version::VERSION_MINOR);
        $this->assertSame(3, Version::VERSION_SPECIAL);
        $this->assertSame(4, Version::VERSION_SPECIAL_NUMBER);
    }
}

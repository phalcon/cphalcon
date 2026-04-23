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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\Has;
use Phalcon\Tests\AbstractUnitTestCase;

final class HasTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrHas(): void
    {
        $object = new Has();
        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $actual = $object($collection, 1);
        $this->assertTrue($actual);

        $actual = $object($collection, 'suffix');
        $this->assertTrue($actual);

        $actual = $object($collection, uniqid());
        $this->assertFalse($actual);
    }
}

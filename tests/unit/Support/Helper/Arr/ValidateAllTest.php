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

use Phalcon\Support\Helper\Arr\ValidateAll;
use Phalcon\Tests\AbstractUnitTestCase;

final class ValidateAllTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperArrValidateAll(): void
    {
        $object = new ValidateAll();
        $collection = [2, 3, 4, 5];
        $actual = $object(
            $collection,
            function ($element) {
                return $element > 1;
            },
        );
        $this->assertTrue($actual);
    }
}

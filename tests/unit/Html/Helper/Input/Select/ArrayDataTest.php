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

namespace Phalcon\Tests\Unit\Html\Helper\Input\Select;

use Phalcon\Html\Helper\Input\Select\ArrayData;
use Phalcon\Tests\AbstractUnitTestCase;

final class ArrayDataTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testGetOptionsReturnsFlatArray(): void
    {
        $data     = new ArrayData(['1' => 'Ferrari', '2' => 'Ford']);
        $expected = ['1' => 'Ferrari', '2' => 'Ford'];
        $actual   = $data->getOptions();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testGetOptionsReturnsNestedArrayForOptgroups(): void
    {
        $input = [
            'Group A' => ['1' => 'Ferrari', '2' => 'Ford'],
            '3'       => 'Toyota',
        ];
        $data   = new ArrayData($input);
        $actual = $data->getOptions();
        $this->assertSame($input, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testGetOptionsReturnsEmptyArrayWhenNoData(): void
    {
        $data     = new ArrayData();
        $expected = [];
        $actual   = $data->getOptions();
        $this->assertSame($expected, $actual);
    }
}

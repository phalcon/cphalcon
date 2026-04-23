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

use InvalidArgumentException;
use Phalcon\Html\Helper\Input\Select\ResultsetData;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Html\Helper\Input\Select\Fake\FakeResultset;

final class ResultsetDataTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testConstructorThrowsOnInvalidUsingCount(): void
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('requires exactly two values');

        new ResultsetData(new FakeResultset([]), ['id']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testGetOptionsReturnsEmptyArrayForEmptyResultset(): void
    {
        $data = new ResultsetData(new FakeResultset([]), ['id', 'name']);

        $this->assertSame([], $data->getOptions());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testGetOptionsReturnsValueLabelPairsFromArrayRows(): void
    {
        $rows = [
            ['id' => '1', 'name' => 'Ferrari'],
            ['id' => '2', 'name' => 'Ford'],
        ];

        $data     = new ResultsetData(new FakeResultset($rows), ['id', 'name']);
        $expected = ['1' => 'Ferrari', '2' => 'Ford'];

        $this->assertSame($expected, $data->getOptions());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testGetOptionsReturnsValueLabelPairsFromObjects(): void
    {
        $row1 = $this->getMockBuilder(\stdClass::class)
                     ->addMethods(['readAttribute'])
                     ->getMock();
        $row1->method('readAttribute')
             ->willReturnMap([['id', '1'], ['name', 'Ferrari']]);

        $row2 = $this->getMockBuilder(\stdClass::class)
                     ->addMethods(['readAttribute'])
                     ->getMock();
        $row2->method('readAttribute')
             ->willReturnMap([['id', '2'], ['name', 'Ford']]);

        $data   = new ResultsetData(new FakeResultset([$row1, $row2]), ['id', 'name']);
        $actual = $data->getOptions();

        $this->assertSame(['1' => 'Ferrari', '2' => 'Ford'], $actual);
    }
}

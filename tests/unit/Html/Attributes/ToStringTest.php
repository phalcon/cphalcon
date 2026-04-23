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

namespace Phalcon\Tests\Unit\Html\Attributes;

use Phalcon\Html\Attributes;
use Phalcon\Html\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class ToStringTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-02
     */
    public function testHtmlAttributesToString(): void
    {
        $attributes = new Attributes(
            [
                'type'  => 'text',
                'class' => 'form-control',
                'name'  => 'q',
                'value' => '',
            ]
        );

        $this->assertSame(
            'type="text" name="q" value="" class="form-control" ',
            (string)$attributes
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-09-26
     */
    public function testHtmlAttributesToStringException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Value at index: "value" type: "array" cannot be rendered'
        );

        $attributes = new Attributes(
            [
                'name'  => 'q',
                'value' => ['one' => 'two'],
            ]
        );

        $result = (string)$attributes;
    }
}

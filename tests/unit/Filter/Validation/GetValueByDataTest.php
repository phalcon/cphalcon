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

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Filter\Validation;
use Phalcon\Tests\Support\Models\EntityWithPublic;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class GetValueByDataTest extends AbstractUnitTestCase
{
    public const NAME = 'John Doe';

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function testFilterValidationGetValueByDataArray(): void
    {
        $data = [
            'name' => self::NAME,
        ];

        $validation = new Validation();
        $value      = $validation->getValueByData($data, 'name');

        $expected = $data['name'];
        $actual   = $value;
        $this->assertSame($expected, $actual);
    }

    public function testFilterValidationGetValueByDataObject(): void
    {
        $data = new EntityWithPublic(self::NAME);

        $validation = new Validation();
        $value      = $validation->getValueByData($data, 'name');

        $expected = $data->name;
        $actual   = $value;
        $this->assertSame($expected, $actual);
    }
}

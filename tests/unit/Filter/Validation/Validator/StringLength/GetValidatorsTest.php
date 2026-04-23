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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetValidatorsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthGetValidators(): void
    {
        $validator = new StringLength();

        $this->assertTrue(is_array($validator->getValidators()), 'Is array');

        $this->assertEmpty($validator->getValidators(), 'Empty validators');
        $this->assertCount(0, $validator->getValidators(), 'Empty validators');

        $validator = new StringLength([
            'min' => 5,
            'max' => 15,
        ]);

        $this->assertTrue(is_array($validator->getValidators()), 'Is array');

        $this->assertNotEmpty($validator->getValidators(), 'Not empty validators');
        $this->assertCount(2, $validator->getValidators(), 'Has 2 validators');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthValidateEmptyThrows(): void
    {
        $validator  = new StringLength();
        $validation = new Validation();
        $validation->add('name', $validator);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('does not have any validator added');
        $validation->validate(['name' => 'hello']);
    }
}

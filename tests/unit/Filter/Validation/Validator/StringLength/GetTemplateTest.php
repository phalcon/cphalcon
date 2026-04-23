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

use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTemplateTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthGetTemplate(): void
    {
        $validator = new StringLength();

        $expected = 'The field :field is not valid for ' . StringLength::class;

        $this->assertSame(
            $expected,
            $validator->getTemplate(),
            'Default template message'
        );

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $this->assertInstanceOf(StringLength::class, $actual, 'Instance of StringLenght');

        $this->assertSame(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}

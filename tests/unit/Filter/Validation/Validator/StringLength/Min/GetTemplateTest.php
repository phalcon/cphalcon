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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength\Min;

use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTemplateTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthMinGetTemplate(): void
    {
        $validator = new Min();

        $expected = 'Field :field must be at least :min characters long';
        $this->assertSame($expected, $validator->getTemplate(), 'Default template message for Min');

        $validator->setTemplate('');

        $expected = 'The field :field is not valid for ' . Min::class;
        $this->assertSame($expected, $validator->getTemplate(), 'Default template message');

        $expected = 'New custom template';
        $validator->setTemplate($expected);

        $this->assertSame($expected, $validator->getTemplate(), 'New template message');
    }
}

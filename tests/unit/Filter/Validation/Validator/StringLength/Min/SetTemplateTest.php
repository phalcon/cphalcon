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

final class SetTemplateTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthMinSetTemplate(): void
    {
        $validator = new Min();

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $this->assertInstanceOf(Min::class, $actual, 'Instance of Min');

        $this->assertSame(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}

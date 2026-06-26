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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength\Max;

use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetTemplateTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthMaxSetTemplate(): void
    {
        $validator = new Max();

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $this->assertInstanceOf(Max::class, $actual, 'Instance of Max');

        $this->assertSame(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}

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

namespace Phalcon\Tests\Unit\Forms\Element\Select;

use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Forms\Element\Select;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetValidatorsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsElementSelectGetValidators(): void
    {
        $element = new Select('country');
        $this->assertSame([], $element->getValidators());

        $validator = new PresenceOf();
        $element->addValidator($validator);

        $this->assertSame([$validator], $element->getValidators());
    }
}

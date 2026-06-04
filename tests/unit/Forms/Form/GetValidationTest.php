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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Filter\Validation;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetValidationTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormGetValidation(): void
    {
        $form = new Form();
        $this->assertNull($form->getValidation());

        $validation = new Validation();
        $form->setValidation($validation);
        $this->assertSame($validation, $form->getValidation());
    }
}

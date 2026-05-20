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

use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormConstruct(): void
    {
        $form = new Form();

        $this->assertCount(0, $form);
        $this->assertNull($form->getEntity());

        $entity       = new stdClass();
        $entity->name = 'phalcon';

        $form = new Form($entity);
        $this->assertSame($entity, $form->getEntity());
    }
}

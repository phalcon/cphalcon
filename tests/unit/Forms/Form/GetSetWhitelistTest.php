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

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class GetSetWhitelistTest extends AbstractUnitTestCase
{
    public function testGetWhitelistReturnsEmptyArrayByDefault(): void
    {
        $form = new Form();

        $this->assertSame([], $form->getWhitelist());
    }

    public function testSetWhitelistStoresAndReturnsValue(): void
    {
        $form = new Form();

        $result = $form->setWhitelist(['first', 'last']);

        $this->assertSame($form, $result);
        $this->assertSame(['first', 'last'], $form->getWhitelist());
    }

    public function testBindUsesFormWhitelistWhenNoWhitelistArgument(): void
    {
        $form = new Form();
        $form->add(new Text('first'));
        $form->add(new Text('last'));
        $form->setWhitelist(['first']);

        $entity = new stdClass();
        $form->bind(['first' => 'John', 'last' => 'Doe'], $entity);

        $this->assertSame('John', $form->getValue('first'));
        $this->assertNull($form->getValue('last'));
    }

    public function testGetValueCallsFormGetterMethod(): void
    {
        $form = new Form();
        $form->setWhitelist(['first', 'last']);

        $result = $form->getValue('whitelist');

        $this->assertSame(['first', 'last'], $result);
    }
}

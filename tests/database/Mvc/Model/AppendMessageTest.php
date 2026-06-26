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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Messages\Message;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class AppendMessageTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelAppendMessage(): void
    {
        $invoice = new Invoices();

        $message  = new Message('The message', 'inv_title', 'InvalidValue', 42);
        $returned = $invoice->appendMessage($message);

        $this->assertSame($invoice, $returned);

        $messages = $invoice->getMessages();

        $this->assertCount(1, $messages);
        $this->assertSame('The message', $messages[0]->getMessage());
        $this->assertSame('inv_title', $messages[0]->getField());
        $this->assertSame('InvalidValue', $messages[0]->getType());
        $this->assertSame(42, $messages[0]->getCode());
    }
}

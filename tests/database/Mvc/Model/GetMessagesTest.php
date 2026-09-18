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

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\ObjectsMigration;
use Phalcon\Tests\Support\Models\InvoicesValidationCode;
use Phalcon\Tests\Support\Models\Objects;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class GetMessagesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->clear();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetMessages(): void
    {
        $record         = new Objects();
        $record->obj_id = 1;
        $result         = $record->save();
        $this->assertFalse($result);

        $messages = $record->getMessages();

        $expectedCount = 2;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        $expected = 'obj_type is required';
        $actual   = $messages[1]->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-09-30
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetMessagesFiltered(): void
    {
        $record         = new Objects();
        $record->obj_id = 1;
        $result         = $record->save();
        $this->assertFalse($result);

        $messages = $record->getMessages();

        $expectedCount = 2;
        $this->assertCount($expectedCount, $messages);

        /**
         * Filter by field obj_name
         */
        $messages = $record->getMessages('obj_name');

        $expectedCount = 1;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        /**
         * Filter by field obj_type
         */
        $messages = $record->getMessages('obj_type');

        $expectedCount = 1;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_type is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        /**
         * Filter by both fields
         */
        $messages = $record->getMessages(['obj_name', 'obj_type']);

        $expectedCount = 2;
        $this->assertCount($expectedCount, $messages);

        $expected = 'obj_name is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        $expected = 'obj_type is required';
        $actual   = $messages[1]->getMessage();
        $this->assertSame($expected, $actual);
    }

    /**
     * The `code` option of a validator used in the model validation() must
     * reach the message that getMessages() returns.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12645
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-03
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetMessagesWithValidationCode(): void
    {
        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));

        $invoice = new InvoicesValidationCode();

        $this->assertFalse($invoice->create());

        $messages = $invoice->getMessages();

        $this->assertCount(1, $messages);

        $expected = 'The title is required';
        $actual   = $messages[0]->getMessage();
        $this->assertSame($expected, $actual);

        $expected = 20;
        $actual   = $messages[0]->getCode();
        $this->assertSame($expected, $actual);
    }
}

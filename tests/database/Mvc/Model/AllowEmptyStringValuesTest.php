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

use Phalcon\Mvc\Model;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\StringFieldMigration;
use Phalcon\Tests\Support\Models\ModelWithStringField;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class AllowEmptyStringValuesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getPdoConnection();
        new StringFieldMigration($connection);
    }

    public function tearDown(): void
    {
        Settings::reset();

        $this->tearDownDatabase();
    }

    /**
     * A column declared `not null` with no default rejects an empty string.
     * allowEmptyStringValues() puts the field on the exception list, and the
     * same save() then goes through.
     *
     * @author Nikolay Sumrak <nikolassumrak@gmail.com>
     * @since  2017-11-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAllowEmptyStringValues(): void
    {
        Model::setup(
            [
                'exceptionOnFailedSave' => false,
                'notNullValidations'    => true,
            ]
        );

        $model        = new ModelWithStringField();
        $model->field = '';
        $model->disallowEmptyStringValue();

        $this->assertFalse($model->save());

        $model->allowEmptyStringValue();

        $this->assertTrue($model->save());
    }

    /**
     * Without the field on the exception list, the empty string counts as null
     * and the implicit PresenceOf message names the field.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12688
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-09
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelAllowEmptyStringValuesNotSet(): void
    {
        Model::setup(
            [
                'exceptionOnFailedSave' => false,
                'notNullValidations'    => true,
            ]
        );

        $model        = new ModelWithStringField();
        $model->field = '';
        $model->disallowEmptyStringValue();

        $this->assertFalse($model->save());

        $messages = $model->getMessages();

        $this->assertCount(1, $messages);
        $this->assertSame('field is required', $messages[0]->getMessage());
        $this->assertSame('PresenceOf', $messages[0]->getType());
    }
}

<?php

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Abonnes;
use Phalcon\Validation\Validator\Email;
use Phalcon\Validation\Validator\ExclusionIn;
use Phalcon\Validation\Validator\InclusionIn;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength\Max;
use Phalcon\Validation\Validator\StringLength\Min;
use Phalcon\Validation\Validator\Uniqueness;

use function date;

class ModelsValidatorsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    public function testValidatorsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->testValidatorsRenamed($I);
    }

    public function testValidatorsPostgresql(IntegrationTester $I)
    {
        $this->setupPostgres();
        $this->testValidatorsRenamed($I);
    }

    public function testValidatorsSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();
        /**
         * @todo Check Sqlite - tests lock up
         */
//        $this->testValidatorsRenamed($I);
    }

    protected function testValidatorsRenamed(IntegrationTester $I)
    {
        $connection = $this->container->getShared('db');

        $I->assertTrue(
            $connection->delete('subscriptores')
        );

        $createdAt = date('Y-m-d H:i:s');


        //Save with success
        $abonne = new Abonnes();

        $abonne->courrierElectronique = 'fuego@hotmail.com';
        $abonne->creeA                = $createdAt;
        $abonne->statut               = 'P';

        $I->assertTrue(
            $abonne->save()
        );


        //PresenceOf
        $abonne = new Abonnes();

        $abonne->courrierElectronique = 'fuego1@hotmail.com';
        $abonne->creeA                = null;
        $abonne->statut               = 'P';

        $I->assertFalse(
            $abonne->save()
        );


        $messages = $abonne->getMessages();

        $I->assertCount(1, $messages);

        $I->assertEquals(
            PresenceOf::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'creeA',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'La date de création est nécessaire',
            $messages[0]->getMessage()
        );


        //Email
        $abonne = new Abonnes();

        $abonne->courrierElectronique = 'fuego?=';
        $abonne->creeA                = $createdAt;
        $abonne->statut               = 'P';

        $I->assertFalse(
            $abonne->save()
        );

        $I->assertCount(
            1,
            $abonne->getMessages()
        );

        $messages = $abonne->getMessages();

        $I->assertEquals(
            Email::class,
            $messages[0]->getType()
        );
        $I->assertEquals(
            'courrierElectronique',
            $messages[0]->getField()
        );
        $I->assertEquals(
            'Le courrier électronique est invalide',
            $messages[0]->getMessage()
        );


        //ExclusionIn
        $abonne->courrierElectronique = 'le_fuego@hotmail.com';
        $abonne->statut               = 'X';

        $I->assertFalse(
            $abonne->save()
        );

        $messages = $abonne->getMessages();

        $I->assertEquals(
            ExclusionIn::class,
            $messages[0]->getType()
        );
        $I->assertEquals(
            'statut',
            $messages[0]->getField()
        );
        $I->assertEquals(
            'L\'état ne doit être "X" ou "Z"',
            $messages[0]->getMessage()
        );


        //InclusionIn
        $abonne->statut = 'A';

        $I->assertFalse(
            $abonne->save()
        );

        $messages = $abonne->getMessages();

        $I->assertEquals(
            InclusionIn::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'statut',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'L\'état doit être "P", "I" ou "w"',
            $messages[0]->getMessage()
        );


        //Uniqueness validator
        $abonne->courrierElectronique = 'fuego@hotmail.com';
        $abonne->statut               = 'P';

        $I->assertFalse(
            $abonne->save()
        );

        $messages = $abonne->getMessages();

        $I->assertEquals(
            Uniqueness::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'courrierElectronique',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'Le courrier électronique doit être unique',
            $messages[0]->getMessage()
        );


        //Regex validator
        $abonne->courrierElectronique = 'na_fuego@hotmail.com';
        $abonne->statut               = 'w';

        $I->assertFalse(
            $abonne->save()
        );

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), Regex::class);
        $I->assertEquals($messages[0]->getField(), 'statut');
        $I->assertEquals($messages[0]->getMessage(), "L'état ne correspond pas à l'expression régulière");


        //too_long
        $abonne->courrierElectronique = 'personwholivesinahutsomewhereinthecloud@hotmail.com';
        $abonne->statut               = 'P';

        $I->assertFalse(
            $abonne->save()
        );

        $messages = $abonne->getMessages();

        $I->assertEquals(
            Max::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'courrierElectronique',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'Le courrier électronique est trop long',
            $messages[0]->getMessage()
        );


        //too_short
        $abonne->courrierElectronique = 'a@b.co';
        $abonne->status               = 'P';

        $I->assertFalse(
            $abonne->save()
        );

        $messages = $abonne->getMessages();

        $I->assertEquals(
            Min::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'courrierElectronique',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'Le courrier électronique est trop court',
            $messages[0]->getMessage()
        );


        // Issue #885
        $abonne = new Abonnes();

        $abonne->courrierElectronique = 'fuego?=';
        $abonne->creeA                = null;
        $abonne->statut               = 'P';

        $I->assertFalse(
            $abonne->save()
        );

        $I->assertCount(
            2,
            $abonne->getMessages()
        );


        $messages = $abonne->getMessages();

        $I->assertEquals(
            PresenceOf::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'creeA',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'La date de création est nécessaire',
            $messages[0]->getMessage()
        );


        $I->assertEquals(
            Email::class,
            $messages[1]->getType()
        );

        $I->assertEquals(
            'courrierElectronique',
            $messages[1]->getField()
        );

        $I->assertEquals(
            'Le courrier électronique est invalide',
            $messages[1]->getMessage()
        );


        $messages = $abonne->getMessages('creeA');

        $I->assertCount(1, $messages);

        $I->assertEquals(
            PresenceOf::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'creeA',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'La date de création est nécessaire',
            $messages[0]->getMessage()
        );


        $messages = $abonne->getMessages('courrierElectronique');

        $I->assertCount(1, $messages);

        $I->assertEquals(
            Email::class,
            $messages[0]->getType()
        );

        $I->assertEquals(
            'courrierElectronique',
            $messages[0]->getField()
        );

        $I->assertEquals(
            'Le courrier électronique est invalide',
            $messages[0]->getMessage()
        );
    }
}

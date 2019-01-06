<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Abonnes;
use function date;

class ModelsValidatorsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function testValidatorsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->testValidatorsRenamed($I);
    }

    protected function testValidatorsRenamed(IntegrationTester $I)
    {
        $connection = $this->container->getShared('db');

        $success = $connection->delete("subscriptores");
        $I->assertTrue($success);

        $createdAt = date('Y-m-d H:i:s');

        //Save with success
        $abonne                       = new Abonnes();
        $abonne->courrierElectronique = 'fuego@hotmail.com';
        $abonne->creeA                = $createdAt;
        $abonne->statut               = 'P';
        $I->assertTrue($abonne->save());

        //PresenceOf
        $abonne                       = new Abonnes();
        $abonne->courrierElectronique = 'fuego1@hotmail.com';
        $abonne->creeA                = null;
        $abonne->statut               = 'P';
        $I->assertFalse($abonne->save());

        $I->assertCount(1, $abonne->getMessages());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "PresenceOf");
        $I->assertEquals($messages[0]->getField(), "creeA");
        $I->assertEquals($messages[0]->getMessage(), "La date de création est nécessaire");

        //Email
        $abonne                       = new Abonnes();
        $abonne->courrierElectronique = 'fuego?=';
        $abonne->creeA                = $createdAt;
        $abonne->statut               = 'P';
        $I->assertFalse($abonne->save());

        $I->assertCount(1, $abonne->getMessages());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "Email");
        $I->assertEquals($messages[0]->getField(), "courrierElectronique");
        $I->assertEquals($messages[0]->getMessage(), "Le courrier électronique est invalide");

        //ExclusionIn
        $abonne->courrierElectronique = 'le_fuego@hotmail.com';
        $abonne->statut               = 'X';
        $I->assertFalse($abonne->save());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "ExclusionIn");
        $I->assertEquals($messages[0]->getField(), "statut");
        $I->assertEquals($messages[0]->getMessage(), 'L\'état ne doit être "X" ou "Z"');

        //InclusionIn
        $abonne->statut = 'A';
        $I->assertFalse($abonne->save());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "InclusionIn");
        $I->assertEquals($messages[0]->getField(), "statut");
        $I->assertEquals($messages[0]->getMessage(), 'L\'état doit être "P", "I" ou "w"');

        //Uniqueness validator
        $abonne->courrierElectronique = 'fuego@hotmail.com';
        $abonne->statut               = 'P';
        $I->assertFalse($abonne->save());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "Uniqueness");
        $I->assertEquals($messages[0]->getField(), "courrierElectronique");
        $I->assertEquals($messages[0]->getMessage(), 'Le courrier électronique doit être unique');

        //Regex validator
        $abonne->courrierElectronique = 'na_fuego@hotmail.com';
        $abonne->statut               = 'w';
        $I->assertFalse($abonne->save());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "Regex");
        $I->assertEquals($messages[0]->getField(), "statut");
        $I->assertEquals($messages[0]->getMessage(), "L'état ne correspond pas à l'expression régulière");

        //too_long
        $abonne->courrierElectronique = 'personwholivesinahutsomewhereinthecloud@hotmail.com';
        $abonne->statut               = 'P';
        $I->assertFalse($abonne->save());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "TooLong");
        $I->assertEquals($messages[0]->getField(), "courrierElectronique");
        $I->assertEquals($messages[0]->getMessage(), "Le courrier électronique est trop long");

        //too_short
        $abonne->courrierElectronique = 'a@b.co';
        $abonne->status               = 'P';
        $I->assertFalse($abonne->save());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "TooShort");
        $I->assertEquals($messages[0]->getField(), "courrierElectronique");
        $I->assertEquals($messages[0]->getMessage(), "Le courrier électronique est trop court");

        // Issue #885
        $abonne                       = new Abonnes();
        $abonne->courrierElectronique = 'fuego?=';
        $abonne->creeA                = null;
        $abonne->statut               = 'P';
        $I->assertFalse($abonne->save());

        $I->assertCount(2, $abonne->getMessages());

        $messages = $abonne->getMessages();
        $I->assertEquals($messages[0]->getType(), "PresenceOf");
        $I->assertEquals($messages[0]->getField(), "creeA");
        $I->assertEquals($messages[0]->getMessage(), "La date de création est nécessaire");

        $I->assertEquals($messages[1]->getType(), "Email");
        $I->assertEquals($messages[1]->getField(), "courrierElectronique");
        $I->assertEquals($messages[1]->getMessage(), "Le courrier électronique est invalide");

        $messages = $abonne->getMessages('creeA');
        $I->assertCount(1, $messages);
        $I->assertEquals($messages[0]->getType(), "PresenceOf");
        $I->assertEquals($messages[0]->getField(), "creeA");
        $I->assertEquals($messages[0]->getMessage(), "La date de création est nécessaire");

        $messages = $abonne->getMessages('courrierElectronique');
        $I->assertCount(1, $messages);
        $I->assertEquals($messages[0]->getType(), "Email");
        $I->assertEquals($messages[0]->getField(), "courrierElectronique");
        $I->assertEquals($messages[0]->getMessage(), "Le courrier électronique est invalide");
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
}

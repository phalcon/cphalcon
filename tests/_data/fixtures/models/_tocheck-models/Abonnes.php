<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Messages\Message;
use Phalcon\Mvc\Model;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email as EmailValidator;
use Phalcon\Validation\Validator\ExclusionIn as ExclusionInValidator;
use Phalcon\Validation\Validator\InclusionIn as InclusionInValidator;
use Phalcon\Validation\Validator\PresenceOf as PresenceOfValidator;
use Phalcon\Validation\Validator\Regex as RegexValidator;
use Phalcon\Validation\Validator\StringLength as StringLengthValidator;
use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;

class Abonnes extends Model
{
    public function initialize()
    {
        $this->setSource('subscriptores');
    }

    public function beforeValidation()
    {
        if ($this->courrierElectronique == 'marina@hotmail.com') {
            $this->appendMessage(
                new Message('Désolé Marina, mais vous n\'êtes pas autorisé ici')
            );

            return false;
        }
    }

    public function beforeDelete()
    {
        if ($this->courrierElectronique == 'fuego@hotmail.com') {
            //Sorry this cannot be deleted
            $this->appendMessage(
                new Message('Désolé, ce ne peut pas être supprimé')
            );

            return false;
        }
    }

    public function validation()
    {
        $validator = new Validation();

        $validator->add(
            'creeA',
            new PresenceOfValidator(
                [
                    'message' => 'La date de création est nécessaire',
                ]
            )
        );

        $validator->add(
            'courrierElectronique',
            new EmailValidator(
                [
                    'field'   => '',
                    'message' => 'Le courrier électronique est invalide',
                ]
            )
        );

        $validator->add(
            'statut',
            new ExclusionInValidator(
                [
                    'domain'  => ['X', 'Z'],
                    'message' => 'L\'état ne doit être "X" ou "Z"',
                ]
            )
        );

        $validator->add(
            'statut',
            new InclusionInValidator(
                [
                    'domain'  => ['P', 'I', 'w'],
                    'message' => 'L\'état doit être "P", "I" ou "w"',
                ]
            )
        );

        $validator->add(
            'courrierElectronique',
            new UniquenessValidator(
                [
                    'message' => 'Le courrier électronique doit être unique',
                    'model'   => $this,
                ]
            )
        );

        $validator->add(
            'statut',
            new RegexValidator(
                [
                    'pattern' => '/[A-Z]/',
                    'message' => "L'état ne correspond pas à l'expression régulière",
                ]
            )
        );

        $validator->add(
            'courrierElectronique',
            new StringLengthValidator(
                [
                    'min'            => '7',
                    'max'            => '50',
                    'messageMinimum' => 'Le courrier électronique est trop court',
                    'messageMaximum' => 'Le courrier électronique est trop long',
                ]
            )
        );

        return $this->validate($validator);
    }

    public function columnMap()
    {
        return [
            'id'         => 'code',
            'email'      => 'courrierElectronique',
            'created_at' => 'creeA',
            'status'     => 'statut',
        ];
    }
}

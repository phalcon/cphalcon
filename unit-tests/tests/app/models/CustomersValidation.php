<?php
/**
 * CustomersValidation.php
 * CustomersValidation
 *
 * Model for the users table with validation rules
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Mvc\Model\Message as Message;
use \Phalcon\Mvc\Model\Validator\PresenceOf as PresenceOfValidator;
use \Phalcon\Mvc\Model\Validator\Email as EmailValidator;
use \Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
use \Phalcon\Mvc\Model\Validator\InclusionIn as InclusionInValidator;
use \Phalcon\Mvc\Model\Validator\Uniqueness as UniquenessValidator;
use \Phalcon\Mvc\Model\Validator\Regex as RegexValidator;
use \Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;

class CustomersValidation extends Customers
{
    public function beforeValidation()
    {
        if ($this->email == 'marina@hotmail.com') {
            $this->appendMessage(
                new Message(
                    'Sorry Marina, but your are not allowed here',
                    'email',
                    'InsertConstraint'
                )
            );
            return false;
        }
    }

    public function beforeDelete()
    {
        if ($this->email == 'fuego@hotmail.com')
        {
            $this->appendMessage(
                new Message(
                    'Sorry this cannot be deleted',
                    'email',
                    'DeleteConstraint'
                )
            );
            return false;
        }
    }

    public function validation()
    {

        $this->validate(
            new PresenceOfValidator(array('field' => 'created_at'))
        );

        $this->validate(
            new StringLengthValidator(
                array(
                    'field' => 'email',
                    'min'   => '7',
                    'max'   => '50'
                )
            )
        );

        $this->validate(
            new EmailValidator(array('field' => 'email'))
        );

        $this->validate(
            new ExclusionInValidator(
                array(
                    'field'  => 'status',
                    'domain' => array('X', 'Z')
                )
            )
        );

        $this->validate(
            new InclusionInValidator(
                array(
                    'field'  => 'status',
                    'domain' => array('P', 'I', 'w')
                )
            )
        );

        $this->validate(
            new UniquenessValidator(array('field' => 'email'))
        );

        $this->validate(
            new RegexValidator(
                array(
                    'field'   => 'status',
                    'pattern' => '/[A-Z]/'
                )
            )
        );

        if ($this->validationHasFailed() == true)
        {
            return false;
        }
    }
}

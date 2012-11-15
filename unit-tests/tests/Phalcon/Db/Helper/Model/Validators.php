<?php
/**
 * Validators.php
 * Db_Helper_Validators
 *
 * Tests the \Phalcon\Db Model Validators component
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

class Db_Helper_Model_Validators extends Phalcon_Test_ModelTestCase
{
    /**
     * Tests saving data in the model which has validators
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-08
     */
    public function testSave()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual = $customer->save();

        $this->assertTrue($actual, 'Record was not saved successfully');
    }

    /**
     * Tests PresenceOf validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testPresenceOf()
    {
        $this->emptyTable('customers');

        $createdAt = null;

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual   = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'PresenceOf',
            'created_at',
            "The field 'created_at' is required"
        );
    }

    /**
     * Tests Email validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testEmail()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'fuego==';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'email',
            'email',
            "Value of field 'email' must have a valid e-mail format"
        );
    }

    /**
     * Tests ExclusionIn validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testExclusionIn()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'X';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'exclusion',
            'status',
            "Value of field 'status' must not be part of list: X, Z"
        );
    }

    /**
     * Tests InclusionIn validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testInclusionIn()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'A';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'inclusion',
            'status',
            "Value of field 'status' must be part of list: P, I, w"
        );
    }

    /**
     * Tests Uniqueness validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testUniqueness()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $customer->save();

        // New record with the same email
        $customer = new CustomersValidation();
        $customer->document_id = 2;
        $customer->customer_id = 'A02';
        $customer->email = 'fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'unique',
            'email',
            "Value of field 'email' is already present in another record"
        );
    }

    /**
     * Tests Regex validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testRegex()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'na_fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'w';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'regex',
            'status',
            "Value of field 'status' doesn't match regular expression"
        );
    }

    /**
     * Tests StringLength validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testStringLengthLong()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'personwholivesinahutsomewhereinthecloud@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'too_long',
            'email',
            "Value of field 'email' exceeds the maximum 50 characters"
        );
    }

    /**
     * Tests StringLength validator
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testStringLengthShort()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'a@b.co';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');
        $this->_checkMessages(
            $messages,
            'too_short',
            'email',
            "Value of field 'email' is less than the minimum 7 characters"
        );
    }

    /**
     * Tests the beforeValidation event
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testBeforeValidation()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'marina@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual = $customer->save();
        $messages = $customer->getMessages();

        $this->assertFalse($actual, 'Record was saved successfully');

        $this->_checkMessages(
            $messages,
            'InsertConstraint',
            'email',
            "Sorry Marina, but your are not allowed here"
        );
    }

    /**
     * Tests the beforeDelete event
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    public function testBeforeDelete()
    {
        $this->emptyTable('customers');

        $createdAt = date('Y-m-d H:i:s');

        $customer = new CustomersValidation();
        $customer->document_id = 1;
        $customer->customer_id = 'A01';
        $customer->email = 'fuego@hotmail.com';
        $customer->created_at = $createdAt;
        $customer->status = 'P';

        $actual = $customer->save();
        $this->assertTrue($actual, 'Record was not saved successfully');

        $actual   = $customer->delete();
        $messages = $customer->getMessages();

        $this->_checkMessages(
            $messages,
            'DeleteConstraint',
            'email',
            "Sorry this cannot be deleted"
        );
    }

    /**
     * Private helper to assert messages
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-09
     */
    private function _checkMessages($messages, $type, $field, $message)
    {
        $this->assertGreaterThan(
            0,
            count($messages),
            "{$type} does not return a message"
        );

        $messageKey = -1;
        if (count($messages) > 0)
        {
            foreach ($messages as $key => $item)
            {
                if ($item->getType() == $type)
                {
                    $messageKey = $key;
                    break;
                }
            }
        }

        if ($messageKey > -1)
        {
            $this->assertEquals($messages[$messageKey]->getType(), $type);
            $this->assertEquals($messages[$messageKey]->getField(), $field);
            $this->assertEquals($messages[$messageKey]->getMessage(), $message);
        }
        else
        {
            $this->assertTrue(false, "No messages defined for {$type}");
        }
    }
}

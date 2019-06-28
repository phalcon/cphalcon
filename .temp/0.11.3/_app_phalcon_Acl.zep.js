[
    {
        "type": "comment",
        "value": "**\n * This file is part of the Phalcon Framework.\n *\n * (c) Phalcon Team <team@phalconphp.com>\n *\n * For the full copyright and license information, please view the LICENSE.txt\n * file that was distributed with this source code.\n *",
        "file": "\/app\/phalcon\/Acl.zep",
        "line": 11,
        "char": 9
    },
    {
        "type": "namespace",
        "name": "Phalcon",
        "file": "\/app\/phalcon\/Acl.zep",
        "line": 57,
        "char": 2
    },
    {
        "type": "comment",
        "value": "**\n * This component allows you to manage ACL lists. An access control list (ACL)\n * is a list of permissions attached to an object. An ACL specifies which users\n * or system processes are granted access to objects, as well as what operations\n * are allowed on given objects.\n *\n *```php\n * use Phalcon\\Acl;\n * use Phalcon\\Acl\\Operation;\n * use Phalcon\\Acl\\Subject;\n * use Phalcon\\Acl\\Adapter\\Memory;\n *\n * $acl = new Memory();\n *\n * \/\/ Default action is deny access\n * $acl->setDefaultAction(Acl::DENY);\n *\n * \/\/ Create some operations\n * $adminsOperation = new Operation(\"Administrators\", \"Super-User role\");\n * $guestsOperation = new Operation(\"Guests\");\n *\n * \/\/ Add \"Guests\" operation to acl\n * $acl->addOperation($roleGuests);\n *\n * \/\/ Add \"Designers\" operation to acl\n * $acl->addOperation(\"Designers\");\n *\n * \/\/ Define the \"Customers\" subject\n * $customersSubject = new Subject(\"Customers\", \"Customers management\");\n *\n * \/\/ Add \"customers\" subject with a couple of operations\n * $acl->addSubject($customersSubject, \"search\");\n * $acl->addSubject($customersSubject, [\"create\", \"update\"]);\n *\n * \/\/ Set access level for operations into subjects\n * $acl->allow($guestsOperation->getName(), \"Customers\", \"search\");\n * $acl->allow(\"Guests\", \"Customers\", \"create\");\n * $acl->deny($guestsOperation->getName(), \"Customers\", \"update\");\n *\n * \/\/ Check whether operation has access to the operations\n * $acl->isAllowed(\"Guests\", \"Customers\", \"edit\"); \/\/ Returns 0\n * $acl->isAllowed($guestsOperation->getName(), \"Customers\", \"search\"); \/\/ Returns 1\n * $acl->isAllowed($guestsOperation->getName(), \"Customers\", \"create\"); \/\/ Returns 1\n *```\n *",
        "file": "\/app\/phalcon\/Acl.zep",
        "line": 58,
        "char": 8
    },
    {
        "type": "class",
        "name": "Acl",
        "abstract": 1,
        "final": 0,
        "definition": {
            "constants": [
                {
                    "type": "const",
                    "name": "ALLOW",
                    "default": {
                        "type": "int",
                        "value": "1",
                        "file": "\/app\/phalcon\/Acl.zep",
                        "line": 60,
                        "char": 20
                    },
                    "file": "\/app\/phalcon\/Acl.zep",
                    "line": 61,
                    "char": 9
                },
                {
                    "type": "const",
                    "name": "DENY",
                    "default": {
                        "type": "int",
                        "value": "0",
                        "file": "\/app\/phalcon\/Acl.zep",
                        "line": 61,
                        "char": 19
                    },
                    "file": "\/app\/phalcon\/Acl.zep",
                    "line": 62,
                    "char": 1
                }
            ],
            "file": "\/app\/phalcon\/Acl.zep",
            "line": 58,
            "char": 14
        },
        "file": "\/app\/phalcon\/Acl.zep",
        "line": 58,
        "char": 14
    }
]